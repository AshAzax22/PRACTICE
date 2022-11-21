#A dice game
import random
#file starts:
val=0 #golbal variable to store the random function output
score=0 #global variable to store the score of the user
counter=0# global variable to count number of consecutive hits
Name=""#global variable to store the name
#function to input name
def first():
    global Name
    Name= input("Enter your name: ")
    print('''


''')
    main()

#main fi=unction which calls all other functions
def main():

 #if else conditions as per the wish of the user
 o=menu()
 if(o==1):
     dice()
     menu()
     
 elif(o==2):
     score=0
     first
     
 elif(o==3):
     rules()
     
     
 elif(o==4):
     display()
     
 elif(o==5):
     print("Thank you for playing thr game")
     print("XOXO"*47)
 else:
     print("invalid input")
     menu()
     
 



#function to take input from the user:
def menu():
    print("Select from the following options:")
    print("-*-*"*47)
    print('''


''')
    #possible options available for the user
    print("1) To roll dice")
    print("2) To restart the game")
    print("3) To view the rules")
    print("4) To view your score")
    print("5) To exit the game")
    
    print('''


''')
    o=int(input())
    return o

#funtion for arithmetic and logical operations of the dice :
def dice():
        global counter#calling the variable from global
        print('''


''')
        val=random.randint(1,6)
        i=int(input("Enter your prediction: "))
        if(i<1 or i >6):
            print("invalid input")
            main()#iterating to the main function
        print('''


''')
        if val==1:
            print(''' -------
|       |
|       |
|   O   |
|       |
|       |
 -------


 ''')
            print("the dice rolls as 1")
            if(i==val):
                print("Congrats you guessed the dice roll correctly")
                counter+=1#updating counter for consecutive success
                
                
            else:
                print("Better luck next time")
                counter=0#reset the value of counter in case of a failure
                

                
        elif val==2:
            print(''' -------
|       |
|       |
| O   O |
|       |
|       |
 -------


 ''')
            print("the dice rolls as 2")
            if(i==val):
                counter+=1#updating counter for consecutive success
                print("Congrats you guessed the dice roll correctly")
                
                
            else:
                print("Better luck next time")
                counter=0#reset the value of counter in case of a failure
                

                
        elif val==3:
            print(''' -------
|       |
|   O   |
|       |
| O   O |
|       |
 -------


 ''')
            print("the dice rolls as 3")
            if(i==val):
                counter+=1#updating counter for consecutive success
                print("Congrats you guessed the dice roll correctly")
                
                
            else:
                print("Better luck next time")
                counter=0#reset the value of counter in case of a failure
                



        if val==4:
            print(''' -------
|       |
| O   O |
|       |
| O   O |
|       |
 -------


 ''')
            print("the dice rolls as 4")
            if(i==val):
                counter+=1#updating counter for consecutive success
                print("Congrats you guessed the dice roll correctly")
                
                
            else:
                print("Better luck next time")
                counter=0#reset the value of counter in case of a failure
                


        if val==5:
            print(''' -------
|       |
| O   O |
|   O   |
| O   O |
|       |
 -------


 ''')
            print("the dice rolls as 5")
            if(i==val):
                counter+=1#updating counter for consecutive success
                print("Congrats you guessed the dice roll correctly")
                
                
            else:
                print("Better luck next time")
                counter=0#reset the value of counter in case of a failure
            
                
                
        if val==6:
            print(''' -------
| O   O |
|       |
| O   O |
|       |
| O   O |
 -------


 ''')
            print("the dice rolls as 6")
            if(i==val):
                counter+=1#updating counter for consecutive success
                print("Congrats you guessed the dice roll correctly")
                
                
            else:
                print("Better luck next time")
                counter=0#reset the value of counter in case of a failure
        scorec()
        main()#iterating to the first function
        

#function to update the score
def scorec():
    global score#calling the variable from global
    if counter>1:
        score = score*2
    elif counter ==1:
        score=score+1
    main()#iterating to the first function
    


#function to display the score
def display():
    global score#calling the variable from global
    global Name#calling the variable from global
    print('''


''')
    print("--||"*47)
    print('''


''')
    print(Name,"'s score = ",score)
    print('''


''')
    print("--||"*47)
    print('''


''')
    main()#iterating to the first function


#funtion to display the rules
def rules():
    print('''


''')
    print("/*/*"*47)
    print("-->>  The user has to predict the outcome of the dice roll")
    print("-->> If the user successfully predicts the outcome of the dice the score increases by 1 initially")
    print("-->> If the user successfully predicts the outcome od the dice consecutively the score doubles")
    print("-->> If the user fails to predict the output the multiplier is set to 1 again and the next time score again just increases by 1")
    print("-->> If the user fails in the first place the score stays the samme")
    print("-->>>>>>>>> Enjoy the game<<<<<<<<<<---------")
    print("/*/*"*47)
    print('''


''')
    main()#iterating to the first function
    
first()
    
    
        

        
