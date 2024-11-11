ones = [ "zero", "one", "towo", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
three = [ None, None, "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
hun = "hundred"
thu = "thousand"

def to_word(n):
    if n < 20:
        return ones[n]
    elif n < 100 and n%10 == 0:
        return three[n//10]
    elif n < 100:
        return f"{three[n//10]}-{ones[n%10]}"
    elif n < 1000 and n%100 == 0:
        return f"{ones[n//100]} {hun}"
    elif n < 1000:
        return f"{ones[n//100]} {hun} and {to_word(n%100)}"
    elif n == 1000:
        return f"one {thu}"


# test
n = int(input())
print(to_word(n))
