# Homework 5.1: The UN Problem
Due: Mon Jun 13, 2022 11:59pm <br/>
20 Possible Points
<br/>
<br/>

# Instructions
There are 193 sovereign states that are members of the United Nations (UN), making it the world’s largest intergovernmental organization. Officially, there are six languages and if you were to work there, you are expected to know at least two languages well enough to conduct business. However, the six languages in that list are not the only ones spoken by all the members; they are just the official languages. As you can probably guess, there are typically numerous communications issues that can arise during a general assembly when translators become scarce.

We’ll say two members can converse if they can exchange messages in both directions. Even if they didn’t understand each other’s languages, two members can still converse as long as there is a sequence of members who could translate for them through a sequence of intermediate languages. For example, Julio and George might be able to converse with some help. Julio could speak Spanish to Brian who would translate to Italian for George. When George replies in German, Jacob would translate to English for Henry who would translate back to Spanish for Julio.

When at the UN, there are numerous social events where a lot of different members, all speaking different languages, are expected to converse and discuss issues. Some pairs of members may not be able to converse (even if others are willing to serve as translators). This can lead to all kinds of problems, fights, treaties ripped up, wars started, etc. You’re going to help by asking some of the members to leave. So as to offend as few nation-states as possible, you’d like to ask as few as possible to leave. You need to determine the size of the smallest set of members S
such that if all the members in S leave, all pairs of remaining members can converse.

For example, in the sample run (see below), Fran and Ian can converse, as can Polly and Spencer, but no other pairs of members can converse, so either everyone but Polly and Spencer must leave or everyone but Fran and Ian. Click on each tab for more information.

## Input
Input starts with a positive integer, 1 ≤ N ≤ 100, the number of members in the meeting. This is followed by N lines, each line describing a member. Each of these N lines starts with the member’s name (which is distinct), then the language(s) that the member speaks (this will only be a single language), then a list of 0 to 20 additional languages the member understands but doesn’t speak. All members understand the language they speak. All members and language names are sequences of 1 to 15 letters (a-z and A-Z), numbers, and hyphens. Member names and languages are separated by single spaces.

For example: **Ian Italian French Spanish**

In this case, the name would be “Ian,” who speaks “Italian” and understands “French” and “Spanish.” As mentioned previously, there will always be a single language that is spoken (the one right after the name). Any additional languages they understand will be after that first spoken language, although they might not understand any other language.

## Output
Print a line of output giving the size of the smallest set of members S that should be asked to leave so that all remaining pairs of members can converse.

## Sample Run
    Sample Input 2
    6
    Fran French Italian
    Enid English German
    George German Italian
    Ian Italian French Spanish
    Spencer Spanish Portuguese
    Polly Portuguese Spanish

    Sample output 2

    4