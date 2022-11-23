import random
z=True
while z:
    p=""
    spcl="~!@#$%&*_+-=?/"
    l=int(input("Enter the desired length of the password: "))
    a=s=A=n=True
    while len(p)<l:
        if len(p)==l-4:
            if s:
                p+=spcl[random.randint(0,len(spcl)-1)]
            if a:
                p+=chr(random.randint(65,90))
            if A:
                p+=chr(random.randint(97,122))
            if n:
                p+=chr(random.randint(49,57))
            
        q=random.randint(0,4)
        if q==0:
            p+=spcl[random.randint(0,len(spcl)-1)]
            s+=False
        elif q==1:
            p+=chr(random.randint(65,90))
            a+=False
        elif q==2:
            p+=chr(random.randint(97,122))
            A==False
        else:
            p+=chr(random.randint(49,57))
            n=False

    print("Password: %s"%p)
    while True:
        x=int(input("enter 1 to Try Again 2 to exit: "))
        if x==1:
            break
        elif x==2:
            print("EOL")
            z=False
            break
        else:
            print("invalid input")
        
        
        

