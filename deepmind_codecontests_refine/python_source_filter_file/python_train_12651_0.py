n = int(input())
A = input().split()
max, max_i = 0, 0
Likes = dict()
for a in A:
    if a not in Likes:
        Likes[a] = 1
    else:
        Likes[a] += 1
        if Likes.get(a) > max:
            max = Likes.get(a)
            max_i = int(a)
print(max_i)