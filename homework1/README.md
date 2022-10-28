# Clean Code: Homework 1

## The Self Driving System Problem

You are part of a software development team that has produced a very well Self Driving System for cars. 
The system is being used successfully in cars, so it is not surprising that other industries are also taking notice. You are being contacted by a developer from the railway industry as he likes to use your module.

To "use" the Self Driving System we inherit from it:

```
class Car : public SelfDrivingSystem
```

The Interface we designed looks like this:

```
class SelfDrivingSystem
{
    public:
        virtual void goForward() 

        virtual void goBackward()

        virtual void turnLeft()

        virtual void turnRight()
        
};
```

The railway developer came up with the idea of using the SelfDrivingSystem as a base because:

![UML](https://github.com/bellmann-engineering/clean-code-homework/raw/master/homework1/uml_idea.png)

This looking like a good idea in first place turns out be problematic as trains cannot turn left or right due to the fact that they are on rails.

![UML](https://github.com/bellmann-engineering/clean-code-homework/raw/master/homework1/inheritance_smell.png)

[https://github.com/bellmann-engineering/clean-code-homework/raw/master/homework1/inheritance_smell.cpp
](https://github.com/bellmann-engineering/clean-code-homework/blob/b498ed8af38c3b67ff041f63b1f870eb425ad0e7/homework1/inheritance_smell.cpp) 
