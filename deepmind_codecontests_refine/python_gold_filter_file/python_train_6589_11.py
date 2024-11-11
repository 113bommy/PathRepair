n=int(input())
l=list(map(int,list(input())))

if not(all(l[i]==4 or l[i]==7 for i in range(n))) or n%2==1:
    print("NO")

else:
    if sum(l[:n//2 ])==sum(l[n//2 :]):
        print("YES")
    else:
        print("NO")