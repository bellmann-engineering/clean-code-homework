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

int main() // for the compiler
{


}