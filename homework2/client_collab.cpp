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
        // this method makes use of client's internal state
        int doSomething() 
        {
            return clientInternalDetail1 + clientInternalDetail2;
        }
        // this method uses none of client's internal state,
        // but it is interested in all of collaborator's state.
        // client is doing a lot of "asking"
        int doSomethingElse() 
        {
            return (collaborator.property1 - collaborator.property2)
                    + collaborator.property3;
        }
};

int main() // for the compiler
{


}