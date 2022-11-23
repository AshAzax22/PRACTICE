a=int(input("enter starting of the range "))
b=int(input("enter ending of the range"))
cp=cc=0
for i in range(a,b+1):
    if i==0 or i ==1:
        print("%s is a neither a composite nor a prime number")
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
