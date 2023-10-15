x= True
while x:
    a=int(input("enter starting of the range "))
    b=int(input("enter ending of the range"))
    if a<0 or b <0:
        print("input less than 0 try again")
        continue
    cp=cc=0
    for i in range(a,b+1):
        if i==0 or i ==1:
            print("%s is a neither a composite nor a prime number"%i)
            continue
        f=0
        for j in range(2,i):
            if i%j==0:
                f+=1
        if f>0:
            print("%s is a composite number" %i)
            cc+=1
        else:
            print("%s is a prime number" %i)
            cp+=1
    print("composite numbers: %s"%cc)
    print("prime numbers: %s"%cp)
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
