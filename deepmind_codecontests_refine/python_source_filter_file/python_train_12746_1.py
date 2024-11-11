def is_suitable(s):
    symmetrics = ['A','H','I','M','O','T','U','V','W','X','Y']
    
    if s in symmetrics:
        return True

    elif len(s)==1:
        return True

    elif s==''.join(reversed(s)):
        for i in range(len(s)):
            if s[i] not in symmetrics:
                return False
        return True
    else:
        return True

if __name__ == "__main__":
    s = input()

    if is_suitable(s):
        print("YES")
    else:
        print("NO")