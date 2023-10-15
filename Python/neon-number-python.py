#neon number
x= True
while x:
    a=int(input("Enter a number to check if its a neon number: "))
    s=a*a
    b=0
    while s>0:
        y=s%10
        b+=y
        s//=10
    if(a==b):
        print(a,"is a neon number")
    else:
        print(a ,"is not a neon number")
    r=True
    while r:
        q=int(input("Enter 1 to run again 2 to exit: "))
        if q==1:
            r= False
        elif q==2:
            r=False
            x=False
            print("End of Code")
        else:
            print("Invalid input") 