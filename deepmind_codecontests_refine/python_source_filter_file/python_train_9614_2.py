n = int(input())
arr = list(map(int, input().split()))
a, b, c, d, e = map(int, input().split())
ans = [0, 0, 0, 0, 0]
p = 0

for x in arr:
    p+=x
    while p>=a:
        if p >= a:
            if p >= b:
                if p >= c:
                    if p >= d:
                        if p >= e:
                            k = p//e
                            p -= k*e
                            ans[4] += k
                        else:
                            k = p//d
                            p -= k*d
                            ans[3] += k
                    else:
                        k = p//c
                        p -= k*c
                        ans[2] += k
                else:
                    k = p//b
                    p -= k*b
                    ans[1] += k
            else:
                k = p//a
                p -= k*a
                ans[0] += k
print(" ".join(str(elem) for elem in ans))