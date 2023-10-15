#armstrong number
x= True
while x:
    a=int(input("Enter a number to check if its an armstrong number: "))
    t=a
    c=0
    while t>0:
        c+=1
        t//=10
    t=a
    s=0
    while t>0:
        s+= (t%10)**c
        t//=10
    if s==a:
        print(a,"is an armstrong number")
    else:
        print(a,"is not an armstrong number")
    r=True
    while r:
        y=int(input("Enter 1 to run again 2 to exit: "))
        if y==1:
            r= False
        elif y==2:
            r=False
            x=False
            print("End of Code")
        else:
            print("Invalid input")