n, p, q = list(map(int, input().split()))
s = input().strip()
fps = [x * p for x in range((n // p) + 1)]
fqs = [x * q for x in range((n // q) + 1)]

for fp in fps:
    for fq in fqs:
        if fp + fq == n:
            ps = fps.index(fp)
            qs = fqs.index(fq)
            start = 0
            end = 0
            print(ps + qs)
            for i in range(1, n + 1):
                if start >= n:
                    break
                if i <= ps:
                    end += p
                else:
                    end += q
                print(s[start:end])
                start = end
            exit()
print(-1)