for t in range(int(input())):
    n=int(input())
    val=0
    while(n!=0):
        val+=1
        n//=2
    print(2**(n-1)-1)