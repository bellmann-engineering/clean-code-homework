# Clean Code - Homework 2 - Solution

The given code violates the _Tell Don't Ask_ rule. 

The client's goal is to get some work done with the help of the collaborator. Here we notice the client is more interested in the state of the collaborator than its own internal state. The appropriate refactoring is to move the envied behaviour onto the envied class. The behaviour implemented in the client should be moved over to the collaborator. The collaborator is the one with the state therefore it should have the behaviour.

1. we extract the body of `doSomethingElse`:

```
class Collaborator 
{
    public:
        int property1;
        int property2;
        int property3;
    
        int doSomething() 
        {
            return (property3 * 100) + (property1 - property2);
        }
};

class Client 
{
    private:
        Collaborator collaborator;
        int clientInternalDetail1;
        int clientInternalDetail2;
    
    public:
        Client(Collaborator c) 
        {
            collaborator = c;
            clientInternalDetail1 = 10;
            clientInternalDetail2 = 20;
        }
        
        int doSomething() 
        {
            return clientInternalDetail1 + clientInternalDetail2;
        }

        int doSomethingElse() 
        {
            return calculateSomething();
        }   

        int calculateSomething() 
        {
            return (collaborator.property1 - collaborator.property2)
                    + collaborator.property3;
        }
};
```

2. Then the `calculateSomething` method is then moved onto `Collaborator`. The client now delegates the `doSomethingElse` method to `Collaborator`'s `calculateSomething`. By doing this Client no longer needs to ask Collaborator for its state in order to do the work. 

```
class Collaborator 
{
    private:
        int property1;
        int property2;
        int property3;
    
    public:
        int doSomething() 
        {
            return (property3 * 100) + (property1 - property2);
        }

        int calculateSomething() 
        {
            return (property1 - property2) + property3;
        }
    
};

class Client 
{
    private:
        Collaborator collaborator;
        int clientInternalDetail1;
        int clientInternalDetail2;
    
    public:
        Client(Collaborator c) 
        {
            collaborator = c;
            clientInternalDetail1 = 10;
            clientInternalDetail2 = 20;
        }
        
        // this method makes use of client's internal state
        int doSomething()
        {
            return clientInternalDetail1 + clientInternalDetail2;
        }
        // now client delegates the calculation to collaborator.
        // it no longer knows about property1, 2 and 3 of collaborator.
        int doSomethingElse() 
        {
            return collaborator.calculateSomething();
        }
};
```

3. Now we invent a new class `Substractor` that does the substraction of propery1 and 2. It is passed to the constructor of `Collaborator`. `Substractor` gets the two properties and does the calculation in a own method. 

```
class Substractor
{
    private:
        int property1;
        int property2;

    public:
        int calc() 
        {
            return property1 - property2;
        }
};

class Collaborator 
{
    private:
        Substractor* substractor;
        int property3;
    
    public:
        Collaborator(Substractor* s = nullptr)
        {
            substractor = s;
        }

        int doSomething() 
        {
            return (property3 * 100) + substractor->calc();
        }

        int calculateSomething() 
        {
            return substractor->calc() + property3;
        }
    
};

class Client 
{
    private:
        Collaborator collaborator;
        int clientInternalDetail1;
        int clientInternalDetail2;
    
    public:
        Client(Collaborator c) 
        {
            collaborator = c;
            clientInternalDetail1 = 10;
            clientInternalDetail2 = 20;
        }
        
        // this method makes use of client's internal state
        int doSomething()
        {
            return clientInternalDetail1 + clientInternalDetail2;
        }
        // now client delegates the calculation to collaborator.
        // it no longer knows about property1, 2 and 3 of collaborator.
        int doSomethingElse() 
        {
            return collaborator.calculateSomething();
        }
};
```

In conclusion, keep a lookout for _Feature Envy_. This is a sign that objects are asking and not telling. 