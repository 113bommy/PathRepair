import re


string_length = input()
string = input()

brackets_pattern, sep, replacement, empty_bracket = "\(.*?\)", "\_+", "", "()"
max_length, number_of_words_in_brackets = 0, 0
brackets = re.findall(pattern=brackets_pattern, string=string)
for bracket in brackets:
    if bracket != empty_bracket:
        words_in_bracket = re.split(pattern=sep, string=bracket.lstrip("(").rstrip(")"))
        for word in words_in_bracket:
            if word:
                number_of_words_in_brackets += 1

string = re.sub(pattern=brackets_pattern, string=string, repl=replacement)
words = re.split(pattern=sep, string=string)
for word in words:
    max_length = max_length if max_length > len(word) else len(word)

print(f"{max_length} {number_of_words_in_brackets}")
