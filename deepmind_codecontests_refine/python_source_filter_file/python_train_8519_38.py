def main():
    from collections import Counter as ct
    n=int(input())
    a=ct(list(map(int,input().split())))
    if len(a.keys()) not in [1,2]:
        print("No")
        return 0
    if len(a.keys())==1:
        a=list(a.items())
        if a==[(2,3)]:
            print("Yes")
            return 0
        if 2*a[0][0]<=a[0][1]:
            print("Yes")
        else:
            print("No")
        return 0
    i=min(a.keys())
    iv=a[i]
    j=max(a.keys())
    jv=a[j]
    if j-i!=1:
        print("No")
        return 0
    if iv>i:
        print("No")
        return 0
    k=2*(i-iv+1)
    if jv>=k:
        print("Yes")
    else:
        print("No")
main()