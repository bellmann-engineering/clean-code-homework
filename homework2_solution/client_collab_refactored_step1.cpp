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

int main() // for the compiler
{


}