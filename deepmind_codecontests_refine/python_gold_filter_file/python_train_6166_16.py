n, m = list(map(int, input().split()))
occs = {}
a = []
revs = {}
for i in range(n):
    s = input()
    a.append(s)
    revs[s] = s[::-1]
    if s in occs.keys():
        occs[s] += 1
    else:
        occs[s] = 1
start = ""
end = ""
middle = ""
for i in range(n):
    if a[i] in occs.keys():
        n1 = occs[a[i]]
        n2 = 0
        del occs[a[i]]
        if revs[a[i]] in occs.keys():
            n2 = occs[revs[a[i]]]
            ss = min(n1, n2)
            start += a[i] * ss
            end = (revs[a[i]] * ss) + end
            del occs[revs[a[i]]]
        if a[i] == revs[a[i]] and (min(n1, n2) < n1 or min(n1, n2) < n2) and middle == "":
            middle = a[i]
ans = start + middle + end
print(len(ans))
print(ans)



