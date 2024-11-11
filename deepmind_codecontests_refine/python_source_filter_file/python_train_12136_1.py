n = int(input())
string = input()

output = [0]*(n)

if n % 2 == 0:
    curr = n//2 - 1
    output[n//2 - 1] = string[0]
    for i in range(1 , n):
        if i%2 == 1:
            output[curr - i] = string[i]
            curr -= i
        else:
            output[curr + i] = string[i]
            curr += i

else:
    curr = n // 2
    output[n//2] = string[0]
    for i in range(1 , n):
        if i%2 == 1:
            output[curr - i] = string[i]
            curr -= i
        else:
            output[curr + i] = string[i]
            curr += i

print("".join(output))