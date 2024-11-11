n, m, k = map(int, input().split());
a = list(map(int, input().split()));
a.sort(reverse = True);
if sum(a)+k-n < m:
    print(-1);
elif k >= m:
    print(0);
else:
    for i in range (1, n):
        if sum(a[:i])+k-i >= m:
            print(i)
            break;

