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

int main() // for the compiler
{


}
