# Feedback

Nota final = 8

## Programa 1 - Interruptor LED
- Esquema elétrico do circuito: OK
- Máquina de estados: as transições E1->ON e E2->OFF deveriam ser disparadas por tempo e não por estado do botão. Note que não há necessidade de ficar trocando a sensibilidade da interrupção, já que dependeria apenas do tempo.
- Código-fonte: Não deveria ser verificado o valor do botão nos estados E1 e E2. Também não há necessidade de trocar a sensibilidade das interrupções.
- Nota: 7

## Programa 2 - Voltímetro Digital
- Esquema elétrico do circuito: OK
- Máquina de estados: OK
- Código-fonte: não há necessidade de verificar o tempo dentro do botao_isr já que usamos máquina de estados para filtrar o repique por tempo. Note que o delay deveria estar fora do 'case' para que ditar a taxa de atualização da máquina de estados.
- Nota: 9
