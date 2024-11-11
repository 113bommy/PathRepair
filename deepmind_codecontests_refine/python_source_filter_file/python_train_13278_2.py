s = ["I hate ", "I love "]

n = int(input())
_ = 0
for _ in range(n-1):
    print(s[_ % 2] + "that", end=" ")
print(s[(_+1) % 2] + "it")
