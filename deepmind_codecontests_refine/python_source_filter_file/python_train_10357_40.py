s = int(input())
ones = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
teens = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
tens = ["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

if s < 10:
    print(ones[s])
elif s < 20:
    print(teens[10 - s])
elif s < 100:
    print(tens[s // 10]) if s % 10 == 0 else print(tens[s // 10] + "-" + ones[s % 10])
