def commonCharacters(strings):
    commonChars = set(strings[0])
    for s in strings:
        for char in commonChars:
            if char not in s:
                commonChars.remove(char)
    return list(char)
