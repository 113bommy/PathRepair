instruction = input()

def check():
    for c in instruction:
        if c in "HQ9+":
            return 'YES'
    return 'NO'

print(check())