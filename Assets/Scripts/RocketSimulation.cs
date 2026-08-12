using System.Collections.Generic;
using System.IO;
using UnityEngine;

public class RocketSimulation : MonoBehaviour
{
    public string fileName = "rocket_data.csv";

    private List<float> heights = new List<float>();
    private int index = 0;

    void Start()
    {
        string path = Path.Combine(Application.dataPath, fileName);

        if (File.Exists(path))
        {
            string[] lines = File.ReadAllLines(path);

            for (int i = 1; i < lines.Length; i++) // skip header
            {
                string[] values = lines[i].Split(',');
                float height = float.Parse(values[1]);
                heights.Add(height);
            }
        }
    }

    void Update()
    {
        if (index < heights.Count)
        {
            transform.position = new Vector3(0, heights[index], 0);
            index++;
        }
    }
}