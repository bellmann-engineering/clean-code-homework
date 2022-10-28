LSP (_Liskov Substitution Principle_) is violated when we try to remove features. `NotImplementedException` (or similar) is the biggest violation sign.

![UML](https://github.com/bellmann-engineering/clean-code-homework/blob/5a36e378dd84daf110bf62e0b21a47a056dd29de/homework1_solution/uml.png)

You should favor multiple smaller interfaces in face of bigger ones; it is less likely to violate the principle (will talk more in Interface Segregation Principle)

Breaking the LSP principle almost always leads to hard-to-find bugs.

Sometimes is hard to not violate the principle. For example in the .NET framework we can find that 
the `Array` class implements `IList` interface that has `Add` method. `Array.Add` invocation 
throws a `NotSupportedException`. Is it a clear violation of the _Liskov Substitution Principle_.

This problem appeared with .NET 2.0 (when generics were introduced) 
and since Microsoft didn't want to break the backward compatibility they made this compromise.

# Solution
So what can we do about it? How can the railway developers use our logic as well without violating LSP.
A good approach would be the use ISP (_Interface Segregation Principle_):

Since the problem was with TurnRight or Left, we can split the interface into `Turnable` and `Drivable` interfaces. 
Now, objects can choose what they do and implement only the needed methods.

![UML](https://github.com/bellmann-engineering/clean-code-homework/blob/5a36e378dd84daf110bf62e0b21a47a056dd29de/homework1_solution/uml_split.png
)

So why didn't I also break the `ITurnable` interface? I could have defined an `ITurnRight` and `ITurnLeft` interface. 
Having the methods split into two interfaces would have added code complexity with zero benefits. This is how the principle might make your codebase too granular. 

Don't confuse this principle with the _Single Responsibility Principle_. At a first glance, they might seem similar, but they target different problems. The _Single Responsibility Principle_ tries to help you define a class around a single reason for the change. The _Interface Segregation Principle_ is a blueprint for how to define interfaces. 
A class can implement as many interfaces as it wants. The fewer the methods in the interface the better. But don't overdo it. 

Find a full code sample here: ([car_train_with_isp.cpp](https://github.com/bellmann-engineering/clean-code-homework/blob/5a36e378dd84daf110bf62e0b21a47a056dd29de/homework1_solution/car_train_with_isp.cpp))
