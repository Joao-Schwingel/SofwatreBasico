# SofwatreBasico
Primeiro Trabalho na linguagem C

Para cada pixel da imagem de entrada, após o processo de zoom, será gerada uma matriz de sub-pixels que podem apenas estar ligados em função de sua respectiva cor (vermelho, verde, azul), ou desligados (preto). A matriz utilizada é organizada com um arranjo de três colunas e três linhas, contendo as cores vermelho, verde e azul, nessa ordem, como ilustra o exemplo [A]  [A] As bordas escuras são apresentadas apenas a título ilustrativo.:

Cada sub-pixel pode apenas estar ligado ou desligado, dessa forma será necessário reduzir a precisão das cores da imagem de entrada e utilizar diferentes padrões de sub-pixel para ter-se quatro níveis de brilho. Para cada pixel da imagem de entrada, devem ser gerados os seguintes padrões:

Para níveis de cor de 0 a 74, todos os sub-pixels devem ser pretos;
Para níveis de cor de 75 a 134, o sub-pixel do meio deve ser da cor respectiva (R, G ou B) e os outros dois devem ser pretos;
Para níveis de cor de 135 a 179, o sub-pixel do meio deve ser preto e os outros dois devem ser da cor respectiva (R, G ou B);
E para níveis de cor de 180 a 255, todos os sub-pixels devem ser de sua cor respectiva.
