set title 'Lakes Daily Ice Concentration Comparison (2023–2024)'
set xlabel 'Day of the Year'
set ylabel 'Ice Concentration (%)'
set grid
set xrange [0:158]
set yrange [0:100]
set xtics 20
set ytics 10
set key top right
set key box
set xtics ("342" 13, "354" 25,  "1" 37, "13" 49, "25" 61, "37" 73, "49" 85, "61" 97, "73" 109, "85" 121, "97" 133, "109" 145)

plot 'Question5&6.txt' using 0:2 with lines title 'Superior'lc rgb '#4E79A7	', \
    'Question5&6.txt'using 0:3 with lines title 'Michigan' lc rgb '#59A14F', \
    'Question5&6.txt'using 0:4 with lines title 'Huron'lc rgb '#9C755F', \
    'Question5&6.txt'using 0:5 with lines title 'Erie' lc rgb '#F28E2B', \
    'Question5&6.txt'using 0:6 with lines title 'Ontario' lc rgb '#76B7B2', \
    'Question5&6.txt'using 0:7 with lines title 'St. Clair' lc rgb '#B07AA1'