def thanos(l):
    if l == sorted(l):
        return len(l)
    else:
        return max(thanos(l[:len(l)//2]),thanos(l[len(l)//2:]))
    
input()
a = [int(x) for x in input().split()]
print(thanos(a))