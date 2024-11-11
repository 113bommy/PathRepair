#https://codeforces.com/problemset/problem/1175/A


tests = int(input())

for each in range(tests):
    n , k = input().split(' ')
    n=int(n)
    k=int(k)
    count=0
    while n!=0:
        if (n%k==0):
            n=n//k
            count+=1
        else:
            rest= n%k
            n-=rest
            count+=rest
    print(int(count))

