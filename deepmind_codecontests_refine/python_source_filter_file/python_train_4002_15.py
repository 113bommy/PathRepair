def main():
    a = input()
    lower = False
    upper = False
    digit = False
    if len(a) >= 5:
        for c in a:
            lower = lower or c.islower()
            upper = upper or c.isupper()
            digit = digit or c.isdigit()
        if lower and upper and lower:
            print("Correct")
        else:
            print("Too weak")
    else:
        print("Too weak")

main()