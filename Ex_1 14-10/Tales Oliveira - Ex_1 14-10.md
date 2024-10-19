# Exercícios para 14/10 - Computação Gráfica

Esta lista de exercicio é para a disciplina **Computação Gráfica** ministrada pelo Prof. [Raimundo Claudio Vasconcelos]()
Por [Tales L. Oliveira.](https://github.com/TalesLimaOliveira)


### 1) O que é computação gráfica?

Subárea da Ciência da Computação que consiste em métodos e técnicas usadas de criação, manipulação e exibição de imagens visuais usando computadores.

Ela envolve o uso de técnicas matemáticas e algoritmos para gerar e transformar gráficos em uma tela, seja para criar imagens bidimensionais (2D), como desenhos e gráficos, ou tridimensionais (3D), como animações, simulações e modelagem de objetos em jogos, filmes ou engenharia.

### 2) Dê exemplos de aplicações para a computação gráfica.

Desenhar formas geométricas, como quadrados e círculos, em um programa de desenho (Paint, Photoshop, Gimp e etc), ou mais complexo, como personagens e cenários realistas em filmes e videogames.

### 3) A computação gráfica se divide em 3 subáreas. Quais são elas e como se relacionam?

**Síntese de Imagens:** Envolve a produção de representações visuais (imagens) a partir de especificações geométricas (formas e estruturas) e atributos visuais (cor, textura, iluminação) dos componentes de uma cena. É o processo de criar imagens digitais de objetos 3D, frequentemente confundido com a própria computação gráfica.

**Processamento de Imagens:** Envolve a transformação de imagens digitais para melhorar suas características visuais. Tanto a imagem original quanto a imagem resultante são representadas visualmente, geralmente sob a forma de uma matriz de pixels.

**Análise de Imagens:** Busca extrair informações ou identificar os componentes de uma imagem a partir de sua representação visual. Em vez de gerar imagens, o foco aqui é entender o conteúdo da imagem existente.

**Objetivo:** Identificar padrões, formas ou objetos em uma imagem, e extrair informações úteis, como reconhecimento facial, detecção de objetos, ou segmentação de imagens.

**Exemplos:** Detecção de faces em sistemas de segurança, análise de imagens médicas para diagnóstico, reconhecimento de caracteres em documentos (OCR).

**Relação entre as subáreas:** Síntese de Imagens cria o conteúdo visual a partir de modelos e especificações. Processamento de Imagens transforma ou melhora esse conteúdo visual, ajustando aspectos como contraste e foco. Análise de Imagens interpreta o conteúdo de uma imagem existente, extraindo informações relevantes ou reconhecendo padrões.

Essas subáreas formam a base da computação gráfica e são aplicadas em áreas como entretenimento, ciência, saúde, e muitas outras.
	
### 4) Qual a finalidade da área Síntese de Imagens? Dê exemplos de aplicação.
**Técnicas principais:** Modelagem (definição das formas e geometrias dos objetos) e Rendering (processo de transformar essas formas em uma imagem final, aplicando luzes, sombras, e texturas).

**Objetivo:** Criar um "mundo" tridimensional no computador. A cena é descrita em termos de sua geometria (posição, forma) e atributos visuais (cor, textura, materiais), e o processo de rendering gera uma matriz de pixels, que representa a imagem final.

**Exemplos:** Criação de gráficos para filmes de animação 3D, videogames e simulações científicas.

### 5) Qual a finalidade da área Processamento de Imagens? Dê exemplos de aplicação.
**Objetivo:** Melhorar ou modificar a imagem, aplicando técnicas como ajuste de contraste, foco, redução de ruídos, ou aplicação de efeitos especiais.

**Exemplos:** Aplicação de filtros em fotos digitais, restauração de imagens antigas, compressão de imagens, remoção de artefatos visuais em fotos.

### 6) É correto afirmar que a área de Visão Artificial depende da área de Processamento de Imagens? Justifique sua resposta.

Sim, a Visão Artificial depende do Processamento de Imagens. O processamento de imagens é necessário para preparar e melhorar a qualidade das imagens, realizando tarefas como redução de ruído, ajuste de contraste e segmentação. Essas técnicas são fundamentais para que os algoritmos de visão artificial possam interpretar e extrair informações úteis das imagens. Em resumo, o processamento de imagens fornece a base para a análise visual realizada pela visão artificial.

### 7) Quais as etapas básicas de um sistema típico de Visão Artificial? Descreva brevemente cada uma dessas etapas.

**Pré-processamento:** Melhoria da imagem para prepará-la para análise. Isso pode incluir a redução de ruídos, ajuste de contraste, correção de iluminação ou redimensionamento da imagem.

**Segmentação:** Separação de diferentes partes ou objetos na imagem, identificando regiões de interesse. A segmentação divide a imagem em componentes, como o objeto e o fundo.

**Extração de Características:** Identificação e coleta de informações relevantes da imagem, como formas, texturas, bordas, ou pontos chave. Essas características são usadas para descrever o objeto visualmente.

**Reconhecimento ou Classificação:** Identificação ou classificação dos objetos presentes na imagem com base nas características extraídas. Isso envolve o uso de algoritmos para determinar o que está na imagem.

**Pós-processamento:** Refinamento dos resultados e tomada de decisões com base na análise da imagem. Pode incluir ajustes finais ou a integração de resultados em sistemas maiores, como controle robótico.

### 8) Qual  a  principal  diferença  entre  aplicações  da  Visualização  Científica  e  da  Visualização  de Informação? Dê exemplos de cada uma delas.

**Visualização Científica:** Focada na representação visual de dados com origem física ou científica, como fenômenos naturais, simulações físicas, ou dados gerados por sensores em experimentos. A visualização científica normalmente lida com dados espaciais e tridimensionais, como imagens médicas ou simulações de fenômenos físicos.

**Objetivo:** Facilitar o entendimento de fenômenos complexos, ajudar na análise de simulações científicas e auxiliar na descoberta de padrões em dados científicos.

**Exemplos:**

Visualização de modelos meteorológicos (como a formação de tempestades).
Visualização de dados médicos, como tomografias ou ressonâncias magnéticas tridimensionais.
Simulações de fluidos ou estudo de dinâmica de fluidos computacional (CFD).

**Visualização de Informação:** Focada na representação de dados abstratos que não possuem uma estrutura física ou espacial inerente, como dados financeiros, estatísticas, ou redes sociais. A visualização de informação lida com dados multidimensionais, categóricos ou temporais, como gráficos, mapas de calor e infográficos.

**Objetivo:** Facilitar o entendimento de grandes volumes de dados abstratos, identificando padrões, tendências e insights de dados que não têm uma estrutura visual clara por si só.

**Exemplos:**

Visualização de dados financeiros, como o movimento de ações em gráficos de linhas ou bolhas.
Mapas de calor para analisar o comportamento de usuários em sites (rastreando onde clicam).
Visualização de redes sociais, mostrando a conexão entre diferentes usuários e a propagação de informações.

Em resumo, a Visualização Científica lida com dados espaciais e físicos (com base no mundo real ou simulado), enquanto a Visualização de Informação trata de dados abstratos que precisam ser organizados de forma visual para serem compreendidos.

### 9) Na década de 80 surgiram os pacotes gráficos. Atualmente temos diversas APIs gráficas, dentre elas a OpenGL. Qual o papel das APIs gráficas?

As APIs gráficas fornecem um conjunto de ferramentas, funções e bibliotecas que permitem aos desenvolvedores criar e manipular gráficos em diferentes ambientes e plataformas de forma mais eficiente e padronizada. Elas abstraem a complexidade de interagir diretamente com o hardware gráfico (como placas de vídeo) e facilitam a criação de gráficos 2D e 3D.
