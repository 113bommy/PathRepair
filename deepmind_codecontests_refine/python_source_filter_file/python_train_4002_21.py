str = input()
if len(str) <= 5:
    print("Too weak\n")
else:
    small = 0
    big = 0
    dig = 0

    for s in str:
        if s.islower():
            small = 1
        if s.isdigit():
            dig = 1

        if s.isupper():
            big = 1

    if small and big and dig:
        print("Correct")
    else:
        print ("Too weak")
