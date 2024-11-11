FirstDigit = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
TenAbove = ["Ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
            "nineteen"]
Second = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
N = input()
if len(N) == 1:
    print(FirstDigit[int(N)])
else:
    if int(N) in range(10, 20):
        print(TenAbove[int(N[1])])
    else:
        print(Second[int(N[0]) - 2], end="")
        print("" if N[1] == '0' else "-" + FirstDigit[int(N[1])])

# UB_CodeForces
# Advice: Don't live the others versions of your life
# Location: At home behind my desk
# Caption: Should study for Internet engineering exam but submitting codes
# CodeNumber: 486
