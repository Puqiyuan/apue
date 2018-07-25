Please ensure that you complete reading this README file, because it including so much
notes about this project. If you feeling confuse any time, please check this README
file carefully.

Before you can successfully make, please create two directory, obj and bin.

The project is the learning notes for the Advanced Programming in the UNIX Environment
book. The project including all codes implement and solutions for exercise problems. The
organization of the project is following the book by chapter, so every chapter have a
directory under top directory. Maybe some other organization will appear in the future
because of learning arrangement. Because I start the project when I studied chapter2, so
there is no directory for chapter1.

For convenient to cooperation, I will illustrate some things about book and programs
organizations.

Firstly, my APUE book is the third edition, PDF file. You can Google it by apue book pdf,
easy to get, note that it's the third edition, PDF file. And I open the book by zathura
tool on Debian, so the actually page number in paper book is different from that zathura
give to me, but the example programs in book ,not exercises programs written and test by
me are named by page number, see this README continue carefully. The page number for
naming example program in book is from zathura tool, not the actually page on that paper
book. If you don't use zathura or don't use Debian, does not matter, the first line of
every example program or exercise in example_programs folder and exercise folder is the
actually page number in the paper book. By using page number that zathura give to me for
example programs naming, I am every convenience for reading and working on this project,
because I don't need to memorize what chapter or what section or what small section I am
reading for naming one example program, just page number, easy to use. If you want to test
these programs while reference APUE book, please careful this convention.

The include folder and lib folder are from author's source codes. The other programs in
each chapter directory are from the author's book as sample programs, but I rewrite and
test it for learning and understanding aims. The exercise folder do by myself.

In each chapter directory, there are two directories existing in any chapter directory,
one is example_programs, it is for put the example programs for testing and rewriting. The
other directory is exercise, for containing exercise problems at the end of each chapter.

The two directories under chapter directory, one is examples_programs including all
example programs in this chapter, every program is named like "pxx.c", where "p" is the
shorthand of "page", and "xxx" is the number of page. This convention also apply to other
chapter directories, so the convention statement will not appear in other directories.

All executable files are added to bin folder.
