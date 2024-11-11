def bears(n1, n2, n3, n4):
    if n2 < 2 * n4 and n4 <= 2 * n3 and n3 <= 2 * n4:
        return 2 * n1, 2 * n2, min(2 * n3, 2 * n4)
    return [-1]


v1, v2, v3, v4 = [int(i) for i in input().split()]
print(*bears(v1, v2, v3, v4), sep='\n')
