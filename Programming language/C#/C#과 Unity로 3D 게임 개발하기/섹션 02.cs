Udemy μ λν°

π΅ 2022. 09. 05. μ

π’ reset νλ©΄ 0, 0, 0μΌλ‘ λμμ΄

π’ q, w, e, r, t, y λ‘ λ¬Όμ²΄λ₯Ό λ€μνκ² μμ§μ

π’ shiftλ₯Ό λλ₯΄λ©΄ νμ΄λΌν€ μ°½μμ μ€λΈμ νΈ λ€μ€ μ ν κ°λ₯

π’ creat emptyλ₯Ό νκ³  μ€λΈμ νΈλ₯Ό λͺ°μ λ£λ κ±° μΆμ²

π’ κ·Έ μ€λΈμ νΈλ₯Ό νλ¦¬νΉνλκ±° μΆμ² (νλ¦¬νΉνλ©΄ λ³κ²½μ¬ν­μ νκΊΌλ²μ λ³κ²½κ°λ₯)


π΅ 2022. 09. 06. ν

π’ void Start() λ©μλ : κ²μμ΄ μμλ¨κ³Ό λμμ νλ²λ§ μ€ν

π’ void Update() λ©μλ : κ²μμ΄ μμλκ³  λμ μ§νλλ λ§€ νλ μλ§λ€ μ€ν

π’ transform.Translate(0.1f, 0, 0);  :  xμ’νλ‘ 0.1μ΄ λν¨

π’ λ³μλ₯Ό μ¬μ©ν΄μ κ°μ μ§μ νκΈ°!!
 --> κ·Έλ¬λ©΄ μμμ κ°μ λ κΉλνκ² μ§μ ν  μ μμ
        κ·Έλ¦¬κ³  κ°μ κ°μ μ¬λ¬λ² μ¬μ©ν  λ μ μ©ν¨!! 
float xValue = 0.01f;
transform.Translate(xValue, 0, 0);


π’ meterial νμ©ν΄μ object μκΉ, μ§κ° λ±λ± λ°κΎΈκΈ°


π’ μ§λ ¬ν νλλ₯Ό μ¬μ©ν΄ μΈμ€νν°μμ κ°μ μμ ν  μ μλλ‘ ν΄μ€λ€.
[SerializeField]float xValue = 0;
[SerializeField]float yValue = 0.02f;         μ΄λ° μμΌλ‘..!!!
[SerializeField]float zValue = 0;


π΅ 2022. 09. 07. μ

π’ Input.GetAxis("Horziontal");
    -->  μνμΌλ‘(x μΆμΌλ‘) ν€λ³΄λμ μλ ₯μ λ°μ μμΉλ₯Ό λ³κ²½


π’ Input.GetAxis("Vertical");   
    --> μμ§μΌλ‘ (z μΆμΌλ‘) ν€λ³΄λμ μλ ₯μ λ°μ μμΉλ₯Ό λ³κ²½


π’ Time.deltaTime
   -->  μ΄κ²μ΄ νμν μ΄μ λ κ°κ°μ μ μ λ€μ μ»΄ν¨ν° λ§λ€ μ¬μμ΄ λ€λ₯΄κΈ° λλ¬Έμ
            νλ μ λν λ¬λΌμ§λ€. κ²°κ΅­ μ΄λ μ»΄ν¨ν°κ° μ’μμ§μ λ°λΌ μΊλ¦­ν°μ μμ§μμ΄λ
            μ΄μμ μλ λν λ¬λΌμ§ μ μλλ°, κ²°κ΅­ μ΄λ μ¬μμ΄ μ’μ μ»΄ν¨ν°κ° 
            κ²μμμ λ μ λ¦¬ν μν©μ μ΄λνλ€.
            μ΄λ₯Ό λ§κΈ° μν΄μλ μ°λ¦¬λ Time.deltaTimeμ΄λΌλ κ²μ μ¬μ©νλ€.
            
            λ§μ½ 1μ΄μ 10νλ μμ΄ λμ€λ μ»΄ν¨ν°λΌλ©΄ μμμ μ λν°κ° 0.1μ κ³±νμ¬ 1μ λ§λ€μ΄μ£Όκ³ ,
            1μ΄μ 100νλ μμ΄ λμ€λ μ»΄ν¨ν°λΌλ©΄ μ λν°κ° μμμ 0.01μ΄λ₯Ό κ³±νμ¬ 1μ λ§λ€μ΄μ€λ€.
   

π’ λ°λΌλ€λλ μΉ΄λ©λΌ λ§λ€κΈ°
1. Pacakge Managerμμ unity registryλ‘ λ€μ΄κ°μ Cinemachine λ€μ΄(λΉμ₯¬μΌμ½λ κΊΌμ Έμμ΄μΌν¨)
2. Cinemachineμμ create virtual camera ν΄λ¦­
3. μΉ΄λ©λΌμ CinemachineBrain μ»΄ν¬λνΈ μΆκ°
4. κ°μ μΉ΄λ©λΌμ Bodyλ₯Ό Framing Transposerλ‘ λ³κ²½
5. κ°μ μΉ΄λ©λΌκ° λ°λΌλ€λ μ€λΈμ νΈ μ€μ 

π’ colider κ·Έλ¦¬κ³  rigidbody μ€λ ₯κ³Ό μΆ©λ


π΅ 2022. 09. 08. λͺ©

π’ Start() λ©μλ : μ λν°μμ μμ λ²νΌ λλ₯΄λ©΄ λ°λ‘ μ€νν΄μ£Όλ λ©μλ

π’ Update() λ©μλ: κ²μμ΄ μ€νλλ λμ νλ μλ¨μλ‘ κ³μν΄μ μ€νν΄μ£Όλ λ©μλ

λ©μλλ₯Ό κΌ­ μ νμ©νμ!!

 void Update()
    {                           // Axis λ» : μ€μ¬μ 
        MovePlayer();
    }

 void MovePlayer()
    {
        float xValue = Input.GetAxis("Horizontal") * Time.deltaTime * moveSpeed;  // Horizontal : μνμ 
        float zValue = Input.GetAxis("Vertical") * Time.deltaTime * moveSpeed;  // Vertical : μμ§μ

        transform.Translate(xValue, 0, zValue);
    }


π’ OnCollisionEnter() λ©μλ : λ¬Όμ²΄κ°μ μΆ©λμ΄ μ²μ μΌμ΄λ¬μ λ νΈμΆ

   private void OnCollisionEnter(Collision other) 
    {
        Debug.Log("Bumped into a wall");
    }


π’ OnCollisionStay() λ©μλ : λ¬Όμ²΄κ°μ μΆ©λμ΄ μΌμ΄λ ν μΆ©λμ΄ μ§μλ  λ νΈμΆ

   private void OnCollisionStay(Collision other)
    {
        Debug.Log("Bumped into a wall");
    }


π’ OnCollisionExit() λ©μλ : λ¬Όμ²΄κ°μ μΆ©λμ΄ λλλ κ·Έ μκ°μ νΈμΆ

   private void OnCollisionExit(Collision other) 
    {
        Debug.Log("Bumped into a wall");    
    }


π’ GetComponent<MeshRenderer>().material.color = Color.red;
 
  --> Mesh Renderer μ»΄ν¬λνΈμμ materialμ colorλ₯Ό λΉ¨κ°μμΌλ‘ λ°κΎΈμ΄μ£ΌλΌ


π’ Time.time : μκ°μ μλ €μ£Όλ λ³μ 

 -->  Debug.Log(Time.time);
 
π’ μ°Έμ‘° μΊμ±νκΈ°

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dropper : MonoBehaviour
{
    MeshRenderer renderer; 
    Rigidbody rigidbody;
    [SerializeField]float timeToWait = 5f;
    // Start is called before the first frame update
    void Start()
    {
        renderer = GetComponent<MeshRenderer>(); // Caching  
        renderer.enabled = false;

        rigidbody = GetComponent<Rigidbody>();  // Generalization (μΌλ°ν)
        rigidbody.useGravity = false;
    }

    // Update is called once per frame
    void Update()
    {
        if(Time.time > timeToWait)
        {
            renderer.enabled = true;   <-- μ°Έμ‘°νμ΄λ―λ‘ λ€λ₯Έ λ©μλμμ μ€μ ν΄λ μ¬κΈ°μ 
            rigidbody.useGravity = true;
        }
    }
}

π’ νκ·Έ μ¬μ©νκΈ°

public class Scorer : MonoBehaviour
{
    int hits = 0;
    private void OnCollisionEnter(Collision other) 
    {
        if(other.gameObject.tag != "Hit") // λ§μ½ νλ μ΄μ΄ μ€λΈμ νΈμ μΆ©λν μ€λΈμ νΈμ νκ·Έκ° Hitκ° μλλΌλ©΄
        {
            hits++;
            Debug.Log("You've bumped into a thing this many times: " + hits);  // hits κ° μΆλ ₯
        }
    }
}
----------------------------------------------------------------

public class ObjectHit : MonoBehaviour
{
    private void OnCollisionEnter(Collision other) // λ¬Όμ²΄κ°μ μΆ©λμ΄ μ²μ μΌμ΄λ¬μ κ²½μ° νΈμΆ, 
    {
        if(other.gameObject.tag == "Player") // λ§μ½ μ€λΈμ νΈμ νλ μ΄μ΄ νκ·Έλ₯Ό κ°μ§ μ€λΈμ νΈκ° λΆλͺμΉ  κ²½μ°
        {
            GetComponent<MeshRenderer>().material.color = Color.red; // λΉ¨κ°μμΌλ‘ λ³κ²½
            gameObject.tag = "Hit"; // κ·Έλ¦¬κ³  μ΄ μ€λΈμ νΈμ νκ·Έλ₯Ό "Hit"λ‘ λ³κ²½
        }
    }
}
