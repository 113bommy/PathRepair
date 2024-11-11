n, m = map(int, input().split())
dictry = {}
for word in range(m):
    w1, w2 = input().split()
    dictry[w1] = w1 if len(w1) < len(w2) else w2
    
lecture = input().split()
lecture = [dictry[x] for x in lecture]
print (" ".join(lecture))