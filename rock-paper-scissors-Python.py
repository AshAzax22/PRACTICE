import random
c=["rock","paper","scissors"]
c2=["Rock","Paper","Scissors"]
userscore=0
cpuscore=0
n=True
while n:
    x=input("Enter rock,paper or scissors: ")
    if (x not in c) and (x not in c2):
        print("Invalid input")
        continue
    a=random.randint(0,2)
    if x==c[0] or x==c2[0]:
        if a==0:
            print("CPU:",c2[0])
            print("Tie")
        elif a==1:
            print("CPU:",c2[1])
            print("You lose")
            print("Paper covers rock")
            cpuscore+=1
        else:
            print("CPU:",c2[2])
            print("You win")
            print("Rock crushes scissor")
            userscore+=1
    elif x==c[1] or x==c2[1]:
        if a ==0:
            print("CPU:",c2[0])
            print("You win")
            print("Paper covers rock")
            userscore+=1
        elif a==1:
            print("CPU:",c2[1])
            print("Tie")
        else:
            print("CPU:",c2[2])
            print("You lose")
            print("Scissors cut paper")
            cpuscore+=1
    else:
        if a==0:
            print("CPU:",c2[0])
            print("You lose")
            print("Rock crushes scissor")
            cpuscore+=1
        elif a==1:
            print("CPU:",c2[1])
            print("You win")
            print("Scissors cut paper")
            userscore+=1
        else:
            print("CPU:",c2[2])
            print("Tie")
    while True:
        x=int(input("enter 1 to continue 2 to exit: "))
        if x==1:
            break
        elif x==2:
            n=False
            break
        else:
            print("invalid input")
print("userscore=",userscore)
print("cpuscore=",cpuscore)
        

            
        
            
            
            
