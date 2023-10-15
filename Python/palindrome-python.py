#palindrome
x=True
while x:
    s=input("Enter a string to check if its a palindrome: ")
    if(s[::-1]==s):
        print(s,"is a palindrome")
    else:
        print(s,"is not a palindrome")
    s=True
    while s:
        y=int(input("Enter 1 to run again 2 to exit: "))
        if y==1:
            s= False
        elif y==2:
            s=False
            x=False
            print("End of Code")
        else:
            print("Invalid input")  
