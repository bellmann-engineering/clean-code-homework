# Clean Code - Homework 2

_Feature envy_ is a term used to describe a situation in which one object gets at the fields of another object in order to perform some sort of computation or make a decision, rather than asking the object to do the computation itself.

> Methods that make extensive use of another class may belong in another class. 
> Consider moving this method to the class it is so envious of.

Having this in mind we will now look at a piece of code and focus on the `doSomethingElse` method:

In the `Client` class below there are two methods. The doSomething method makes use of all of client's fields. However the doSomethingElse method doesn't use any, but it's very interested in Collaborator's state. This is where client is asking and not telling. It's asking Collaborator for state, not telling it to perform a behaviour on its behalf.

## Tasks:

1. Examine the given code in terms of code smells: [client_collab.cpp](https://github.com/bellmann-engineering/clean-code-homework/blob/master/homework2/client_collab.cpp)
2. Which rule was violated here?
3. Improve the Design of Existing Code in two steps
 - Extract the body of `doSomethingElse` to a new method called `calculateSomething`. The intention is to move this newly extracted method onto `Collaborator`.
 - The `calculateSomething` method then should be moved onto `Collaborator`. The client now delegates the `doSomethingElse` method to `Collaborator`'s `calculateSomething`. By doing this the `Client` no longer needs to _ask_ Collaborator for its state in order to do the work. Instead, it asks Collaborator to do the work for it. This follow the - the object that has the data does the work - approach.
 - Make a new class `Substractor` that does the work of 
 ```
 (property1 - property2)
 ```
 from `doSomething()` and `calculateSomething()` in the `Collaborator`.
 Pass an instance of the `Substractor` class to the `Collaborator` in the constructor. 
 _Note_: Do not forget to also move ``property1` and `property2` to the new
4. Notice that now neither the Client had to be changed nor the interface of Collaborator, only its internal implementation.
