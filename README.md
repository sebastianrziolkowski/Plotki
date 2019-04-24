# Wyniki testów

![alt text](https://raw.githubusercontent.com/sebastianrziolkowski/Plotki/master/Plotki.bmp)

# Plotki
<p>
Mamy daną planszę <span class="math">n</span> &times; <span class="math">n</span>. Lewy <del>dolny</del> <ins>górny</ins> róg ma współrzędne <span class="math">(0, 0)</span>, a prawy
<del>górny</del> <ins>dolny</ins> <span class="math">(n-1, n-1)</span>. Współrzędne pól opisane są w kolejności <span class="math">(<i>wiersz</i>, <i>kolumna</i>)</span>.
Po planszy porusza się pionek. Jeden ruch pionka polega na przesunięciu go w poziomie lub pionie o jedno pole.
Pomiędzy poszczególnymi polami mogą być &bdquo;płotki&rdquo; uniemożliwiające przesunięcie pionka z jednego pola na drugie.
Przykładowo  płotek pomiędzy polami <span class="math">(2, 2)</span> i <span class="math">(3,2)</span> powoduje, że aby przejść z pierwszego z tych pól do drugiego
trzeba przejść np. drogę <span class="math">(2, 2) &xrarr; (2, 1) &xrarr; (3, 1) &xrarr; (3, 2)</span>. 
</p>
<p>
Pionek startuje z zadanego pola początkowego oraz wykonuje zadaną liczbę dowolnych ruchów. Napisać program, 
który pomoże ustalić na ile sposobów pionek może wykonać zadaną liczbę ruchów tak, żeby po wykonaniu ostatniego 
z nich znajdował się na zadanym polu końcowym.
</p>
<p>
<h2>Wejście</h2>
<p>
Program wczytuje ze standardowego wejścia liczbę <span class="math">n</span> (<span class="math">1 &le; n &le; 500</span>), liczbę płotków <span class="math">p</span>, a następnie <span class="math">p</span> wierszy z informacją 
o położeniu kolejnych płotków.
</p> 
<p>
Każdy płotek podany jest jako trójka liczb.
Pierwsza z liczb (<span class="math">0</span> lub <span class="math">1</span>) rozstrzyga, czy płotek jest pionowy (liczba <span class="math">0</span>) czy poziomy (liczba <span class="math">1</span>). 
Kolejne dwie liczby oznaczają współrzędne pola położonego nad lub na lewo od płotka. 
</p>
<p>
Po informacji o położeniu płotków program wczytuje dwie liczby całkowite &mdash; współrzędne pola początkowego.
</p>
<p>
Następnie program wczytuje liczbę <span class="math">m</span> (<span class="math">1 &le; m &le; 1000</span>)
&mdash; liczbę zapytań. Każde zapytanie składa się z trzech liczb całkowitych &mdash;
zadanej liczby kroków <span class="math">k</span> (<span class="math">0 &le; k &le; 1000</span>) oraz współrzędnych pola końcowego.
</p>
<h2>Wyjście</h2>
Dla każdego z <span class="math">m</span> zapytań program wyświetla w osobnym wierszu wynik. 
Szukana liczba sposobów na wykonanie zadanej liczby ruchów może być olbrzymia zatem wynikiem jest reszta
z dzielenia szukanej liczby przez 1000000007.
</p>
<h2>Przykład</h2>
<h3>Wejście</h3>
<pre>
3 4
0 0 0
0 0 1
0 1 0
0 1 1
0 0
3
0 0 0
8 0 2
3 2 0
</pre>

<h3>Wyjście</h3>
<pre>
1
7
0
</pre>
<h3>Wyjaśnienie</h3>
W drugim zapytaniu mamy następujące możliwości dotarcia do pola docelowego:
<ol>
  <li><span class="math">(0, 0) &xrarr; (1, 0) &xrarr; (0, 0) &xrarr; (1, 0) &xrarr; (2, 0) &xrarr; (2, 1) &xrarr; (2, 2) &xrarr; (1, 2) &xrarr; (0, 2)</span></li>
  <li><span class="math">(0, 0) &xrarr; (1, 0) &xrarr; (2, 0) &xrarr; (1, 0) &xrarr; (2, 0) &xrarr; (2, 1) &xrarr; (2, 2) &xrarr; (1, 2) &xrarr; (0, 2)</span></li>
  <li><span class="math">(0, 0) &xrarr; (1, 0) &xrarr; (2, 0) &xrarr; (2, 1) &xrarr; (2, 0) &xrarr; (2, 1) &xrarr; (2, 2) &xrarr; (1, 2) &xrarr; (0, 2)</span></li>
  <li><span class="math">(0, 0) &xrarr; (1, 0) &xrarr; (2, 0) &xrarr; (2, 1) &xrarr; (1, 1) &xrarr; (2, 1) &xrarr; (2, 2) &xrarr; (1, 2) &xrarr; (0, 2)</span></li>
  <li><span class="math">(0, 0) &xrarr; (1, 0) &xrarr; (2, 0) &xrarr; (2, 1) &xrarr; (2, 2) &xrarr; (2, 1) &xrarr; (2, 2) &xrarr; (1, 2) &xrarr; (0, 2)</span></li>
  <li><span class="math">(0, 0) &xrarr; (1, 0) &xrarr; (2, 0) &xrarr; (2, 1) &xrarr; (2, 2) &xrarr; (1, 2) &xrarr; (2, 2) &xrarr; (1, 2) &xrarr; (0, 2)</span></li>
  <li><span class="math">(0, 0) &xrarr; (1, 0) &xrarr; (2, 0) &xrarr; (2, 1) &xrarr; (2, 2) &xrarr; (1, 2) &xrarr; (0, 2) &xrarr; (1, 2) &xrarr; (0, 2)</span></li>
</ol>


<h2>Warunki, które powinno spełniać rozwiązanie</h2>
<p>
Program powinien działać w czasie <span class="math">O(n<sup>2</sup>s +  m lg(m))</span> (<span class="math">s</span> jest największą występującą w zapytaniach liczbą kroków) i pamięci <span class="math">O(n<sup>2</sup> + m)</span>.
</p>

<h2>Wskazówka</h2>
<p>
Zadanie należy rozwiązać za pomocą programowania dynamicznego. Rozwiązanie dla <span class="math">k</span> kroków dla zadanego pola docelowego można wyznaczyć z rozwiązań dla <span class="math">k - 1</span> kroków dla pewnych innych (jakich?) pól docelowych.
</p>

Zadanie pochodzi z kursu uczelni UMCS
tichy.umcs.lublin.pl
