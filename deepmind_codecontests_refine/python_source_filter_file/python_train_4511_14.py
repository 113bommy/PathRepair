# cook your dish here
t=int(input())
for g in range(t):
        n=int(input())
        if n%2==0:
                i=1
                while(i<n+1):
                        if i%2!=0:
                                print(i+1,end=" ")
                        else:
                                print(i-1,end=" ")
                        i+=1
                print()
        else:
                print(2,3,1,end=" ")
                i=4
                while(i<n+1):
                        if i%2!=0:
                                print(i+1,end=" ")
                        else:
                                print(i-1,end=" ")
                        i+=1
                print()
                        