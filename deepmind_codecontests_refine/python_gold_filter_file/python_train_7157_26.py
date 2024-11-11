test = input()

for i in range(1, len(test)-1):
    partString = test[i-1]+test[i]+test[i+1]
    if 'A' in partString and 'B' in partString and 'C' in partString:
        print("Yes")
        exit(0)

print("No")