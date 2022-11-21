n=int(input("enter number of elements"))
L=[]
for i in range(0,n):
    x=int(input("Enter element: 6"))
    L.append(x)
l=len(L)
while l>0:
    for i in range(1,l):
        if L[i-1]>L[i]:
            L[i-1],L[i]=L[i],L[i-1]
    l-=1
print("sorted list:",L)
