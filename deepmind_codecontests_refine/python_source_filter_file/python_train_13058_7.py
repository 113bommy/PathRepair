n, t, c = map(int, input().split())
prisoners = list(map(int, input().split()))

start = 0
end = 0
result = 0
for end in range(len(prisoners)):
    if (prisoners[end] > t):
        length = end-start

        if (length >= c):
            result += length-c+1

        start = end+1

if ((end-start) >= c):
    result += end-start-c+2
print(result)
