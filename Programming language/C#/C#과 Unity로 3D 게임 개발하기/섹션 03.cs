π΅ μλ ₯ λ°μΈλ©μ κΈ°λ³Έ

    using System.Collections;
    using System.Collections.Generic;
    using UnityEngine;

    public class Movement : MonoBehaviour
    {
        void Update()
        {
            ProcessThrust();
            ProcessRotation();
        }

        void ProcessThrust() 
        {
            if (Input.GetKey(KeyCode.Space))
            {
                Debug.Log("Pressed SPACE - Thrusting");
            }
        }

        void ProcessRotation()
        {
            if (Input.GetKey(KeyCode.A))
            {
                Debug.Log("Rotate Left");
            }
            else if (Input.GetKey(KeyCode.D))
            {
                Debug.Log("Rotate Right");
            }
        }
}

π΅ AddRelativeForce() λ©μλ

    void ProcessThrust() 
    {
        if (Input.GetKey(KeyCode.Space))
        {
            // rb.AddRelativeForce(0, 1, 0);
            rb.AddRelativeForce(Vector3.up);   // μλ κ°μ λ» yμΆμΌλ‘ μ¬λΌκ°
        }
    }

π΅ transform.Rotate() λ©μλ

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    [SerializeField]float mainThrust = 300f;
    [SerializeField]float rotationThrust = 100f;
    Rigidbody rb;

    void Start()
    {
        rb = GetComponent<Rigidbody>();
    }
    void Update()
    {
        ProcessThrust();
        ProcessRotation();
    }

    private void ProcessThrust() 
    {
        if (Input.GetKey(KeyCode.Space))
        {
            rb.AddRelativeForce(Vector3.up * mainThrust * Time.deltaTime);
        }
    }

    private void ProcessRotation()
    {
        if (Input.GetKey(KeyCode.A)) 
        {
            ApplyRotation(rotationThrust);      
        }
        else if (Input.GetKey(KeyCode.D))
        {
            ApplyRotation(-rotationThrust);
        }
    }

    private void ApplyRotation(float rotationThisFrame)
    {
        transform.Rotate(Vector3.forward * rotationThisFrame * Time.deltaTime);   
    }
}

π΅ rigidbody μ μ½ μ‘°κ±΄

    private void ApplyRotation(float rotationThisFrame)
    {
        rb.freezeRotation = true; // 'μλ μ μ΄λ₯Ό ν  μ μλλ‘ νμ μ κ³ μ νλ€'
        transform.Rotate(Vector3.forward * rotationThisFrame * Time.deltaTime);
        rb.freezeRotation = false; // λ¬Όλ¦¬ μμ€νμ΄ μ μ©λλλ‘ νμ  κ³ μ μ ν΄μ νλ€.
    }
    
    
π΅ μ λν° μ€λμ€  
    
 Main Cameraμ Audio  Listener μ»΄ν¬λνΈ μΆκ°
 Rocketμ Audion Source μ»΄ν¬λνΈ μΆκ°
 
 Audacity (λΉμ νλ‘κ·Έλ¨) μ¬μ©ν΄μ λ΄κ° λ§λ  λ‘μΌ μ¬μ΄λ μνκΈ°
 
 


π΅ AudioSource SFX μ¬μ

    AudioSource audioSource;

    void Start()
    {
        rb = GetComponent<Rigidbody>();
        audioSource = GetComponent<AudioSource>();   // audioSourceλ‘ AudioSource μ»΄ν¬λνΈ 
    }

    void Update()
    {
        ProcessThrust();
        ProcessRotation();
    }

    private void ProcessThrust() 
    {
        if (Input.GetKey(KeyCode.Space))
        {
            rb.AddRelativeForce(Vector3.up * mainThrust * Time.deltaTime);
            if (!audioSource.isPlaying)  // λ§μ½ μ€λμ€κ° μ¬μμ€μ΄ μλλΌλ©΄
            {
                audioSource.Play();  // μ€λμ€ μ¬μ
            }
        }
        else
        {
            audioSource.Stop();  // μ€νμ΄μ€κ° μλλ¦¬λ©΄ μ€λμ€ μ μ§
        }
    }

π΅ SceneMangerλ₯Ό μ¬μ©ν λ¦¬μ€ν°

using UnityEngine;
using UnityEngine.SceneManagement;   // μλ‘μ΄ λ€μμ€νμ΄μ€ μΆκ°

public class CollisionHandler : MonoBehaviour
{
    private void OnCollisionEnter(Collision other) 
    {
        switch (other.gameObject.tag)
        {
            case "Friendly": 
                Debug.Log("This thing is friendly");
                break;    
            case "Finish": 
                Debug.Log("Congrats, yo, you finisihed!");
                ReloadLevel();
                break; 
            case "Fuel": 
                Debug.Log("You piced up fuel!");
                break; 
            default:
                Debug.Log("Sorry, you blew up!");
                ReloadLevel();
                break;
        } 
    }

    void ReloadLevel()  // μ¬μ λ€μ 
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // νμ¬ μ¬μ μ μ₯
        SceneManager.LoadScene(currentSceneIndex); // νμ¬ μ¬μ λ€μ λΆλ¬μ΄
        //SceneManager.LoadScene("SandBox"); 
        //SceneManager.LoadScene(0);  <-- 0μ SandBoxμ μΈλ°μ€ λ²νΈ
    }
}


π΅ λ€μ λ¨κ³ λ‘λ

    void LoadNextLevel() 
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // νμ¬μ¬ μΈλ±μ€ μ μ₯
        int nextSceneIndex = currentSceneIndex + 1; // λ€μ μ¬μ νμ¬ μ¬ μΈλ±μ€μ +1 μ ν΄μ€
        if (nextSceneIndex == SceneManager.sceneCountInBuildSettings) // λ€μμ¬μ΄ νμ¬ μ μ₯λμ΄μλ μ¬λ€μ μμ κ°λ€λ©΄
        {
            nextSceneIndex = 0; // 0μΌλ‘ μ΄κΈ°ν
        }
        SceneManager.LoadScene(nextSceneIndex);  // λ€μμ¬μΌλ‘ μ΄λ
    }

    void ReloadLevel()
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // νμ¬ μ¬μ μ μ₯
        SceneManager.LoadScene(currentSceneIndex); // νμ¬ μ¬μ λ€μ λΆλ¬μ΄
    }



-------------------------------------------------------
    
ππ μ λλ‘ μ€ν μλλ μ΄μ . --->  finishμ μ°©λ₯νλ©΄ λ°λ‘ κ²μ μΊλ¦­ν°λ₯Ό μμ§μ΄μ§ λͺ»νκ³ , 1μ΄ νμ λ€μ λ¨κ³λ‘ λμ΄κ°λ μ½λ μμ±μ νλ €κ³  ν¨.

using UnityEngine;
using UnityEngine.SceneManagement;

public class CollisionHandler : MonoBehaviour
{
    [SerializeField]float delayTime = 1f;
    private void OnCollisionEnter(Collision other) 
    {
        switch (other.gameObject.tag)
        {
            case "Friendly": 
                Debug.Log("This thing is friendly");
                break;    
            case "Finish": 
                Debug.Log("Congrats, yo, you finisihed!");
                Invoke("LoadNextLevel", delayTime);   // LoadNextLevel() λ©μλλ₯Ό 1μ΄ νμ νΈμΆν¨.
                break; 
            default:
                Debug.Log("Sorry, you blew up!");
                StartCrashSequence();
                break;
        } 
    }

    void StartCrashSequence() 
    {
        GetComponent<Movement>().enabled = false;
        Invoke("ReloadLevel", delayTime);
    }

    void LoadNextLevel() 
    {
        GetComponent<Movement>().enabled = false;  // ππ νλ μ΄μ΄λ₯Ό λͺ»μμ§μ΄κ² νλ κ² λν 1μ΄ νμ νΈμΆ λ¨...
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; 
        int nextSceneIndex = currentSceneIndex + 1;
        if (nextSceneIndex == SceneManager.sceneCountInBuildSettings) 
        {
            nextSceneIndex = 0; // 0μΌλ‘ μ΄κΈ°ν
        }
        SceneManager.LoadScene(nextSceneIndex);  // λ€μμ¬μΌλ‘ μ΄λ
    }

    void ReloadLevel()
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // νμ¬ μ¬μ μ μ₯
        SceneManager.LoadScene(currentSceneIndex); // νμ¬ μ¬μ λ€μ λΆλ¬μ΄
    }
}

--- β ν΄κ²°ν¨.

using UnityEngine;
using UnityEngine.SceneManagement;

public class CollisionHandler : MonoBehaviour
{
    [SerializeField]float levelLoadDelay = 1f;
    private void OnCollisionEnter(Collision other) 
    {
        switch (other.gameObject.tag)
        {
            case "Friendly": 
                Debug.Log("This thing is friendly");
                break;    
            case "Finish": 
                Debug.Log("Congrats, yo, you finisihed!");
                StartSuccessSequence();
                break; 
            default:
                Debug.Log("Sorry, you blew up!");
                StartCrashSequence();
                break;
        } 
    }

    void StartCrashSequence() 
    {
        GetComponent<Movement>().enabled = false;
        Invoke("ReloadLevel", levelLoadDelay);
    }
 
    void StartSuccessSequence()   // β finishμ μ°©λ₯νλ©΄ λ°λ‘ μΊλ¦­ν° μμ§μ΄μ§ λͺ»νκ² νκ³ , 1μ΄ ν λ€μλ¨κ³λ‘ λμ΄κ°λ λ©μλ.
    {
        GetComponent<Movement>().enabled = false;
        Invoke("LoadNextLevel", levelLoadDelay);
    }    

    void LoadNextLevel() 
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // νμ¬μ¬ μΈλ±μ€ μ μ₯
        int nextSceneIndex = currentSceneIndex + 1; // λ€μ μ¬μ νμ¬ μ¬ μΈλ±μ€μ +1 μ ν΄μ€
        if (nextSceneIndex == SceneManager.sceneCountInBuildSettings) // λ€μμ¬μ΄ νμ¬ μ μ₯λμ΄μλ μ¬λ€μ μμ κ°λ€λ©΄
        {
            nextSceneIndex = 0; // 0μΌλ‘ μ΄κΈ°ν
        }
        SceneManager.LoadScene(nextSceneIndex);  // λ€μμ¬μΌλ‘ μ΄λ
    }

    void ReloadLevel()
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // νμ¬ μ¬μ μ μ₯
        SceneManager.LoadScene(currentSceneIndex); // νμ¬ μ¬μ λ€μ λΆλ¬μ΄
    }
}


π΅ λ€μ€ μ€λμ€ ν΄λ¦½    (κΌ­ μ€λμ€ν΄λ¦½μ μ€λμ€ νμΌμ μ²¨λΆν΄μ€μΌν¨)


using UnityEngine;
using UnityEngine.SceneManagement;

public class CollisionHandler : MonoBehaviour 
{
    [SerializeField] float levelLoadDelay = 1f;
    [SerializeField] AudioClip success;            // β μ°©λ₯ μ±κ³΅νμ λ μ€λμ€ ν΄λ¦½
    [SerializeField] AudioClip crash;              // β μ₯μ λ¬Όκ³Ό λΆλͺνμ λ μ€λμ€ ν΄λ¦½

    AudioSource audioSource;

    void Start() 
    {
        audioSource = GetComponent<AudioSource>();    // β μ€λμ€ μΊμ±
    }
    
    private void OnCollisionEnter(Collision other) 
    {
        switch (other.gameObject.tag)
        {
            case "Friendly": 
                Debug.Log("This thing is friendly");
                break;    
            case "Finish": 
                Debug.Log("Congrats, yo, you finisihed!");
                StartSuccessSequence();
                break; 
            default:
                Debug.Log("Sorry, you blew up!");
                StartCrashSequence();
                break;
        } 
    }

    void StartCrashSequence() 
    {
        audioSource.PlayOneShot(crash);              // β μ€λμ€ ν΄λ¦½ μ μ©
        GetComponent<Movement>().enabled = false;
        Invoke("ReloadLevel", levelLoadDelay);
    }

    void StartSuccessSequence()
    {
        audioSource.PlayOneShot(success);            // β μ€λμ€ ν΄λ¦½ μ μ©
        GetComponent<Movement>().enabled = false;
        Invoke("LoadNextLevel", levelLoadDelay);
    }    

    void LoadNextLevel() 
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // νμ¬μ¬ μΈλ±μ€ μ μ₯
        int nextSceneIndex = currentSceneIndex + 1; // λ€μ μ¬μ νμ¬ μ¬ μΈλ±μ€μ +1 μ ν΄μ€
        if (nextSceneIndex == SceneManager.sceneCountInBuildSettings) // λ€μμ¬μ΄ νμ¬ μ μ₯λμ΄μλ μ¬λ€μ μμ κ°λ€λ©΄
        {
            nextSceneIndex = 0; // 0μΌλ‘ μ΄κΈ°ν
        }
        SceneManager.LoadScene(nextSceneIndex);  // λ€μμ¬μΌλ‘ μ΄λ
    }

    void ReloadLevel()
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // νμ¬ μ¬μ μ μ₯
        SceneManager.LoadScene(currentSceneIndex); // νμ¬ μ¬μ λ€μ λΆλ¬μ΄
    }
}
