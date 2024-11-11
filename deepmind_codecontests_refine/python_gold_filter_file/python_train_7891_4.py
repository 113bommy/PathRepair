n=input()
print(min(abs(int(n[i:i+3])-753) for i in range(len(n))))