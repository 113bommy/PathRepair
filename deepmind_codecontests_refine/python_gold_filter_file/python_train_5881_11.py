l = int(input())
random = input()
password = input()

s = str(random) + str(password)

def main(l,s):
    count = 0 
    for i in range(len(s)-l):
        if int(s[i]) > int(s[i+l]):
            a = int(s[i]) - int(s[i+l])
            b = (int(s[i+l]) + 10) - int(s[i])
            if a > b:
                count = count + b
            else:
                count = count + a
        else:
            a = int(s[i+l]) - int(s[i])
            b = (int(s[i]) + 10) - int(s[i+l])
            if a > b:
                count = count + b
            else:
                count = count + a
    return count

print(main(l,s))