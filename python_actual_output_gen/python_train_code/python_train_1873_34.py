N = int(input())
odd_8 = [0,105,135,165,189,195]
for i in range(5):
    if odd_8[i] <= N < odd_8[i+1]:
        print(i)