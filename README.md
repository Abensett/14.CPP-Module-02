# 14.CPP-Module-02

* Polymorphisme ad-hoc = surcharge de fonctions = fonctions même nom, paramètres différents 
* Surcharge d’opérateurs
* Forme canonique

## Surchage d'opérateurs :
```
> Notation préfixe (= fonctionnelle) : + 1 1             (+(1,1) ressemnble à la notation fonctionnelle)  
> Notation infixe (= fonctionnelle) : 1 + 1  
> Notation préfixe (= fonctionnelle) : 1 1 + 
```

### Exemple préfixe avec pls opérations : a * b + c / d = + * a b / c d
```
a + b  -> b = right hand side = rhs
```
### Exemple de surcharge d'op:  
``` c
[nom_class] &operator=( [nom_class] const & rhs);     # opérateur d'assignation
 ```
 
## Binary point
 Binary point  is the number of bits used to represent the fractional part of the number.
```
53 and 26.5 is exactly the same. 
The only difference, is the position of binary point. 
In the case of 53, there is "no" binary point.
53 = 11 0101 = 1 * 2**5 + 1 * 2**4 + 1 * 2**2 + 1 * 2**0 = 32 + 16 + 4 + 1 = 53
26.5 = 1 1010.1 = 1 * 2**4 + 1 * 2**3 + 1 * 2**1 + 1 * 2**-1 = 16 + 8 + 2 + 0.5
```
