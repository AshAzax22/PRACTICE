n=int(input("enter the size of the matrix:"))
qn=[]
for i in range(0,n):
        qn.append(input("Enter the values of row separated by comma: ").split(","))
        c=True
        while c:
            v=False
            if len(qn[i])!=n :
                v=True
            if v:
                print("Number of elements entered is inappropriate")
                #alt(qn)
                qn.pop(i)
                qn.append(input("Enter the values of the row again: ").split(","))
            else:
                c=False
for i in qn:
    for j in range(0,len(i)):
            i[j]=int(i[j])
print("The given matrix is : ")
for i in qn:
    for j in i:
        print(j,end=" ")
    print("")
for i in range(0,n):
    for j in range(0,i):
        qn[i][j],qn[j][i]=qn[j][i],qn[i][j]
print("Transpose of the matrix:")
for i in qn:
    for j in i:
        print(j,end=" ")
    print("")
    
