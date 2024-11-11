t = int(input())
for tests in range(t):
    n,a,b = [int(i) for i in input().split(' ')]
    sol = 'No'
    r = 1
    if a==1:
        if (n-1)%b==0:
            sol = 'Yes'
    else:
        rem = n%b
        while r<n:
            if r%b==rem:
                sol = 'Yes'
                break
            r*=a
    print(sol)